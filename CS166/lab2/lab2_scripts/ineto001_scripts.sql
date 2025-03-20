/* drop the table */
DROP TABLE IF EXISTS Students;

/* create the table */
CREATE TABLE Students (SID numeric (9, 0), Name text, Grade float);

/* given in tutorial */
INSERT INTO Students VALUES (860507041, 'John Anderson', 3.67);
INSERT INTO Students VALUES (860309067, 'Tom Kamber', 3.12);

/* select to see specific student */
SELECT SID, Name, Grade FROM Students WHERE SID = 860507041;

/* inserting new person */
INSERT INTO Students VALUES (860704039, 'George Haggerty', 3.67);

/* retrieve students with certain GPA */
SELECT
        *
FROM
        Students
WHERE
        Grade = 3.67;