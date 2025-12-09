export function footer() {

  const year = new Date().getFullYear();

  return `
    <footer class="footer">
      <div class="container">
        <p>© ${year} Abel Villaseca</p>
      </div>
    </footer>
  `
}
