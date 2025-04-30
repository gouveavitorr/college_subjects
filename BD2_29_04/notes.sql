SELECT col1, col2, col3,
    CASE
        WHEN <condition1> THEN <'value1'>
        WHEN <condition2> THEN <'value2'>
        ...
        ELSE <'basically a default value'>
    END
FROM <table1>;

SELECT * FROM col1 JOIN col2 ON col1.att1 = col2.att1;
--optional extras after this: 
--WHERE <condition3> -> filter lines
--GROUP BY ...  -> group lines
--HAVING ... -> filter subgroups
--ORDER BY ... 
--LIMIT OFFSET -> choose how many lines to show
--old outdated version of this command: SELECT * FROM col1, col2 WHERE col1.att1 = col2.att1;

