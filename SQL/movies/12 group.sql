SELECT m.title
FROM movies as m
WHERE m.id in
(
  SELECT s.movie_id
  FROM stars as s
  WHERE s.person_id in
  (
    SELECT p.id
    FROM people as p
    WHERE p.name = 'Bradley Cooper' OR p.name = 'Jennifer Lawrence'
  )

  GROUP BY s.movie_id
  HAVING COUNT(*) > 1
);