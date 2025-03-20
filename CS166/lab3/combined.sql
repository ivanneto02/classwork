/* PROBLEM 1 - PROBLEM 2 at the bottom */
DROP TABLE IF EXISTS Professor CASCADE;
DROP TABLE IF EXISTS Dept CASCADE;
DROP TABLE IF EXISTS Project CASCADE;
DROP TABLE IF EXISTS Graduate CASCADE;
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

-- -- -- --
/* PROBLEM 2 */
-- -- -- --

/* Regular entities */
DROP TABLE IF EXISTS Place CASCADE;
DROP TABLE IF EXISTS Telephone CASCADE;
DROP TABLE IF EXISTS Musicians CASCADE;
DROP TABLE IF EXISTS Instrument CASCADE;
DROP TABLE IF EXISTS Songs CASCADE;
DROP TABLE IF EXISTS Album CASCADE;
DROP TABLE IF EXISTS MuscPerformsSong CASCADE;
DROP TABLE IF EXISTS MuscPlaysInstrument CASCADE;
DROP TABLE IF EXISTS MuscLivesInPlace CASCADE;

/* Entities Table */

CREATE TABLE Telephone (
    phone_no CHAR(15) NOT NULL,
    PRIMARY KEY (phone_no)
);

CREATE TABLE Place (
    _address CHAR(100) NOT NULL,
    phone_no CHAR(15) NOT NULL,
    PRIMARY KEY (_address),
    FOREIGN KEY (phone_no) REFERENCES Telephone(phone_no)
);

CREATE TABLE Musicians (
    ssn CHAR(9) NOT NULL,
    _name CHAR(50),
    PRIMARY KEY (ssn)
);

CREATE TABLE Instrument (
    instrid CHAR(10) NOT NULL,
    dname CHAR(50),
    _key CHAR(2),
    PRIMARY KEY (instrid)
);

CREATE TABLE Album (
    albumident CHAR(10) NOT NULL,
    copyrightDate CHAR(10),
    speed INT,
    title CHAR(100),
    produced_by_ssn CHAR(9) NOT NULL,
    PRIMARY KEY (albumident),
    FOREIGN KEY (produced_by_ssn) REFERENCES Musicians(ssn)
);
/* End of entity tables */

CREATE TABLE Songs (
    songid CHAR(10) NOT NULL,
    title CHAR(100),
    author CHAR(50),
    album_id CHAR(10) NOT NULL,
    PRIMARY KEY (songid),
    FOREIGN KEY (album_id) REFERENCES Album(albumident)
);

/* Many to many tables */
CREATE TABLE MuscPerformsSong (
    musc_ssn CHAR(9) NOT NULL,
    songid CHAR(10) NOT NULL,
    PRIMARY KEY (musc_ssn, songid),
    FOREIGN KEY (musc_ssn) REFERENCES Musicians(ssn),
    FOREIGN KEY (songid) REFERENCES Songs(songid)
);

CREATE TABLE MuscPlaysInstrument (
    musc_ssn CHAR(9) NOT NULL,
    instrid CHAR(10) NOT NULL,
    PRIMARY KEY (musc_ssn, instrid),
    FOREIGN KEY (musc_ssn) REFERENCES Musicians(ssn),
    FOREIGN KEY (instrid) REFERENCES Instrument(instrid)
);

CREATE TABLE MuscLivesInPlace (
    _address CHAR(100) NOT NULL,
    musc_ssn CHAR(9) NOT NULL,
    PRIMARY KEY (musc_ssn, _address),
    FOREIGN KEY (_address) REFERENCES Place(_address),
    FOREIGN KEY (musc_ssn) REFERENCES Musicians(ssn)
);
