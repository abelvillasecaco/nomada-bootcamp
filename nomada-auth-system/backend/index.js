import express from 'express';
import pkg from 'pg';
const { Pool } = pkg;
import bcrypt from 'bcrypt';
import jwt from 'jsonwebtoken';
import cors from 'cors';
import 'dotenv/config';

const app = express();
app.use(express.json());
app.use(cors());

const pool = new Pool({
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD,
  host: process.env.DB_HOST,
  port: process.env.DB_PORT,
  database: process.env.DB_NAME,
});

// Que la contraseña cumpla con los requisitos de seguridad
// (mínimo 6 caracteres, mayúsculas, minúsculas, números, símbolos).

const isPasswordSecure = (password) => {
  const regex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{6,}$/;
  return regex.test(password);
};

// nombre, email y password => req.body

// POST /api/auth/register
app.post('/api/auth/register', async (req, res) => {

  const { nombre, email, password } = req.body;

  if(!nombre || !email || !password) return res.status(400).json({ msg: 'Campos incompletos.'}); // El servidor no ha podido procesar tu solicitud
  if(!isPasswordSecure(password)) return res.status(400).json({ msg: 'Contraseña poco segura.'});

  try{

    const userExists = await pool.query('SELECT * FROM users WHERE email = $1', [email]);
    if(userExists.rows.length > 0) return res.status(400).json({ msg: 'El email ya está registrado.'});

    const salt = await bcrypt.genSalt(10);
    const password_hash = await bcrypt.hash(password, salt);

    const newUser = await pool.query(
      'INSERT INTO users (nombre, email, password_hash) VALUES ($1, $2, $3) RETURNING id, nombre',
      [nombre, email, password_hash]
    );

    const token = jwt.sign({ id: newUser.rows[0].id, nombre: newUser.rows[0].nombre }, process.env.JWT_SECRET, { expiresIn: '1h' });

    res.json({ token, user: newUser.rows[0] });

  }catch(err){
    res.status(500).json({ msg: 'Error en el servidor.' });
  }

});

// newUser.rows

// [
//   {
//     id: 15,
//     nombre:'Juan'
//   },
//   {
//     id: 16,
//     nombre:'Lucho'
//   },
// ]

// newUser.rows[0]

// POST /api/auth/login
app.post('/api/auth/login', async (req, res) => {

  const { email, password } = req.body;

  try{
    const userResult = await pool.query('SELECT * FROM users WHERE email = $1', [email]);
    if(userResult.rows.length === 0) return res.status(400).json({ msg: 'Credenciales inválidas.'});

    const user = userResult.rows[0];

    const isMatch = await bcrypt.compare(password, user.password_hash);
    if(!isMatch) return res.status(400).json({ msg: 'Credenciales inválidas.'});

    await pool.query('UPDATE users SET last_login_at = NOW() WHERE id = $1', [user.id]);

    const token = jwt.sign({ id: user.id, nombre: user.nombre }, process.env.JWT_SECRET, { expiresIn: '1h' });

    res.json({ token, user: { id: user.id, nombre: user.nombre } });

  }catch(err){
    res.status(500).json({ msg: 'Error en el servidor.' });
  }
});

app.listen(process.env.PORT, () => console.log(`Backend corriendo en el puerto: ${process.env.PORT}`));
