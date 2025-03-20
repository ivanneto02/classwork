/* Regular entities */
DROP TABLE IF EXISTS Place CASCADE;
DROP TABLE IF EXISTS Telephone CASCADE;
DROP TABLE IF EXISTS Musicians CASCADE;
DROP TABLE IF EXISTS Instrument CASCADE;
DROP TABLE IF EXISTS Songs CASCADE;
DROP TABLE IF EXISTS Album CASCADE;

/* Many-to-many tables */
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
