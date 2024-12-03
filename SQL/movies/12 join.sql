SELECT title
FROM
(
  SELECT s.movie_id
  FROM
  (
    SELECT p.id
    FROM people AS p
    WHERE p.name = 'Bradley Cooper'
  ) AS bc
    JOIN stars AS s ON s.person_id = bc.id
) AS bcm
  JOIN
  (
    SELECT s.movie_id
    FROM
    (
      SELECT p.id
      FROM people AS p
      WHERE p.name = 'Jennifer Lawrence'
    ) AS jl
      JOIN stars AS s ON s.person_id = jl.id
  ) AS jlm ON jlm.movie_id = bcm.movie_id
  JOIN movies ON movies.id = jlm.movie_id;