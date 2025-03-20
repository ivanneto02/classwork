import logo from './logo.svg';
// import './App.css';
import React from "react";

import {BrowserRouter, Routes, Route} from "react-router-dom";

import {
  createBrowserRouter,
  RouterProvider,
} from "react-router-dom"; 

import About from "./components/pages/About";
import Contact from "./components/pages/Contact";
import Home from "./components/pages/Home";
import Drawing from "./components/pages/Drawing";
import Detecting from "./components/pages/Detecting";

import SideBar from "./components/Sidebar/SideBar";

const router = createBrowserRouter([
  {
    path: "/",
    element: <><SideBar name={"Homepage"}/><Home /></>,
  },
  {
    path: "/home",
    element: <><SideBar name={"Homepage"} /><Home /></>,
  },
  {
    path: "/about",
    element: <><SideBar name={"About"}/><About /></>,
  },
  {
    path: "/contact",
    element: <><SideBar name={"Contact"} /><Contact /></>,
  },
  {
    path: "/draw",
    element: <><SideBar name={"Drawing"} /><Drawing /></>,
  },
  {
    path: "/detect",
    element: <><SideBar name={"Detecting"} /><Detecting /></>,
  },
]);

function App() {

  return (
    <RouterProvider router={router}/>
  );

}

export default App;