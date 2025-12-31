import { defineCollection, z } from 'astro:content';

// Zod
const projectsCollection = defineCollection({
  type: 'content',
  schema: z.object({
    title: z.string(),
    description: z.string(),
    publishDate: z.date(),
    tags: z.array(z.string()), // #proyect #web #react #astro
    link: z.string().url().optional(),
    image: z.string(),
  }),
});

export const collections = {
  'projects': projectsCollection,
}
