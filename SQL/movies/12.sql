SELECT title
FROM
(
  SELECT *
  FROM
  (
    SELECT s.movie_id
    FROM stars as s
    WHERE s.person_id IN
    (
      SELECT id
      FROM people
      WHERE name = 'Bradley Cooper' 
    )
  )
  WHERE movie_id IN
  (
    SELECT movie_id
    FROM stars
    WHERE person_id IN
    (
      SELECT id
      FROM people
      WHERE name = 'Jennifer Lawrence'
    )
  )
) AS m
  JOIN movies ON movies.id = m.movie_id;