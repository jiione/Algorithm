SELECT
    A.ID
    , ifnull(B.COUNT, 0) AS CHILD_COUNT
FROM
    ECOLI_DATA A 
    LEFT JOIN (
        SELECT
            PARENT_ID, COUNT(*) AS COUNT
        FROM
            ECOLI_DATA
        GROUP BY
            PARENT_ID
        HAVING
            PARENT_ID IS NOT NULL
    ) B 
    ON A.ID = B.PARENT_ID
ORDER BY
    ID