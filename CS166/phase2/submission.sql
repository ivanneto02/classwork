-- ENTITIES --
DROP TABLE IF EXISTS Hotel CASCADE;
DROP TABLE IF EXISTS Rooms CASCADE;
DROP TABLE IF EXISTS _User CASCADE;
DROP TABLE IF EXISTS Customer CASCADE;
DROP TABLE IF EXISTS Manager CASCADE;
DROP TABLE IF EXISTS MaintCompany CASCADE;

-- MANY-TO-MANY TABLES --
DROP TABLE IF EXISTS CustomerBooksRooms;
DROP TABLE IF EXISTS ManagerRequestsRepair;
DROP TABLE IF EXISTS MaintCoRepairsRoom;

-- DEFINITIONS

CREATE TABLE _User (
    UserID INT UNIQUE NOT NULL,
    _Password CHAR(11) NOT NULL,
    Email CHAR(50) NOT NULL,
    PRIMARY KEY (UserID)
);

CREATE TABLE Customer (
    CustomerID INT UNIQUE NOT NULL,
    RewardPoints INT NOT NULL,
    _Address CHAR(100),
    PhoneNumber CHAR(12),
    PRIMARY KEY (CustomerID),
    FOREIGN KEY (CustomerID) REFERENCES _User(UserID)
);

CREATE TABLE Manager (
    ManagerID INT UNIQUE NOT NULL,
    Degree CHAR(20),
    Salary INT NOT NULL,
    PRIMARY KEY (ManagerID),
    FOREIGN KEY (ManagerID) REFERENCES _User(UserID)
);

CREATE TABLE Hotel (
    HotelID INT UNIQUE NOT NULL,
    HotelName CHAR(30) NOT NULL,
    Latitude DECIMAL(8,6) NOT NULL,
    Longitude DECIMAL(9,6) NOT NULL,
    ManagedByID INT UNIQUE NOT NULL,
    DateEstablished DATE,
    PRIMARY KEY (HotelID),
    FOREIGN KEY (ManagedByID) REFERENCES Manager(ManagerID)
);

CREATE TABLE Rooms (
    HotelID INT NOT NULL,
    RoomNumber INT NOT NULL,
    PricePerDay INT NOT NULL,
    ImageURL CHAR(100),
    PRIMARY KEY (HotelID, RoomNumber),
    FOREIGN KEY (HotelID) REFERENCES Hotel(HotelID)
);

CREATE TABLE MaintCompany (
    CompanyID INT UNIQUE NOT NULL,
    _Name CHAR(20),
    _Address CHAR(50) NOT NULL,
    PRIMARY KEY(CompanyID)
);

-- MANY-TO-MANY TABLES --
CREATE TABLE CustomerBooksRooms (
    CustomerID INT NOT NULL,
    HotelID INT NOT NULL,
    RoomNumber INT NOT NULL,
    DateOfBooking DATE NOT NULL,
    DurationOfStay CHAR(10),
    Bill CHAR(10),
    PRIMARY KEY (CustomerID, HotelID, RoomNumber),
    FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID),
    FOREIGN KEY (HotelID, RoomNumber) References Rooms(HotelID, RoomNumber)
);

CREATE TABLE MaintCoRepairsRoom (
    CompanyID INT NOT NULL,
    HotelID INT NOT NULL,
    RoomNumber INT NOT NULL,
    PRIMARY KEY (CompanyID, HotelID, RoomNumber),
    FOREIGN KEY (CompanyID) REFERENCES MaintCompany(CompanyID),
    FOREIGN KEY (HotelID, RoomNumber) REFERENCES Rooms(HotelID, RoomNumber)
);

CREATE TABLE ManagerRequestsRepair (
    ManagerID INT NOT NULL,
    HotelID INT NOT NULL,
    CompanyID INT NOT NULL,
    RoomNumber INT NOT NULL,
    PRIMARY KEY (ManagerID, HotelID, CompanyID, RoomNumber),
    FOREIGN KEY (ManagerID) REFERENCES Manager(ManagerID),
    FOREIGN KEY (CompanyID, HotelID, RoomNumber) REFERENCES MaintCoRepairsRoom(CompanyID, HotelID, RoomNumber)
);