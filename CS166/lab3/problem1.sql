DROP TABLE IF EXISTS Professor CASCADE;
DROP TABLE IF EXISTS Dept CASCADE;
DROP TABLE IF EXISTS Project CASCADE;
DROP TABLE IF EXISTS Graduate CASCADE;

/* NOT SURE ABOUT THESE */
DROP TABLE IF EXISTS WorksInDept CASCADE;
DROP TABLE IF EXISTS ProfWorksInProject CASCADE;
DROP TABLE IF EXISTS GradWorksInProject CASCADE;
DROP TABLE IF EXISTS ProjectSupervisor CASCADE;

CREATE TABLE Professor (
    ssn CHAR(9) NOT NULL,
    name CHAR(255),
    age INTEGER,
    rank INTEGER,
    specialty CHAR(255),
    PRIMARY KEY(ssn)
);

CREATE TABLE Dept (
    dno CHAR(10) NOT NULL,
    runner_ssn CHAR(9) NOT NULL,
    dname CHAR(255),
    office INTEGER,
    PRIMARY KEY(dno),
    FOREIGN KEY(runner_ssn) REFERENCES Professor(ssn)
);

CREATE TABLE Project (
    pno CHAR(10) NOT NULL,
    sponsor CHAR(255),
    start_date CHAR(10),
    end_date CHAR(10),
    budget CHAR(50),
    manager_ssn CHAR(9) NOT NULL,
    PRIMARY KEY (pno),
    FOREIGN KEY (manager_ssn) REFERENCES Professor(ssn)
);

CREATE TABLE Graduate (
    ssn CHAR(9) NOT NULL,
    name CHAR(255),
    age INTEGER,
    deg_pg CHAR(255),
    advisor_ssn CHAR(9) NOT NULL,
    majors_in_dept_dno CHAR(255) NOT NULL,
    PRIMARY KEY(ssn),
    FOREIGN KEY (advisor_ssn) REFERENCES Graduate(ssn),
    FOREIGN KEY (majors_in_dept_dno) REFERENCES Dept(dno)
);

/* MANY TO MANY */
CREATE TABLE ProfWorksInProject (
    ssn CHAR(9) NOT NULL,
    pno CHAR(10) NOT NULL,
    PRIMARY KEY (ssn, pno),
    FOREIGN KEY (pno) REFERENCES Project(pno),
    FOREIGN KEY (ssn) REFERENCES Professor(ssn)
);

-- NOT FINISHED YET
CREATE TABLE GradWorksInProject (
    ssn CHAR(9) NOT NULL,
    pno CHAR(10) NOT NULL,
    since CHAR(10),
    supervisor_ssn CHAR(9) NOT NULL,
    PRIMARY KEY (ssn, pno),
    FOREIGN KEY (ssn) REFERENCES Graduate(ssn),
    FOREIGN KEY (pno) REFERENCES Project(pno),
    FOREIGN KEY (supervisor_ssn) REFERENCES Professor(ssn)
);

CREATE TABLE WorksInDept (
    ssn CHAR(9) NOT NULL,
    dno CHAR(10) NOT NULL,
    time_pc INTEGER,
    PRIMARY KEY (ssn, dno),
    FOREIGN KEY (ssn) REFERENCES Professor(ssn),
    FOREIGN KEY (dno) REFERENCES Dept(dno)
);