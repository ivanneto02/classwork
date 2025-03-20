import React from "react";

import { Link } from "react-router-dom";

function BareMenu() {
  return (
    <div>
        <ul>
            <li>
                <Link to="/" > / </Link>
            </li>
            <li>
                <Link to="/home" > Home </Link>
            </li>
            <li>
                <Link to="/draw" > Draw </Link>
            </li>
            <li>
                <Link to="/detect" > Detect </Link>
            </li>
            <li>    
                <Link to="/about" > About </Link>
            </li>
            <li>
                <Link to="/contact" > Contact </Link>
            </li>
        </ul>
    </div>
  );
}
  
export default BareMenu;