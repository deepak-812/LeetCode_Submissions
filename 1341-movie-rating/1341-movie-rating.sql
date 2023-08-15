SELECT * 
FROM (
    SELECT TOP 1 name AS results
    FROM (
        SELECT user_id, COUNT(user_id) AS userCount
        FROM movieRating
        GROUP BY user_id
    ) x
    INNER JOIN users u ON u.user_id = x.user_id
    ORDER BY userCount DESC, u.name ASC
    UNION all
    SELECT TOP 1 title AS results
    FROM (
        SELECT movie_id, AVG(rating * 1.00) AS avgRating
        FROM movieRating
        WHERE FORMAT(created_at, 'yyyy-MM') = '2020-02'
        GROUP BY movie_id
    ) y
    INNER JOIN movies m ON m.movie_id = y.movie_id
    ORDER BY avgRating DESC, m.title ASC
) z;