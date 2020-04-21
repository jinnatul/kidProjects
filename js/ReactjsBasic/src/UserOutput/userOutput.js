import React from 'react';
import './userOutput.css'

const userOutput = (props) => {
    return (
        <div className="userOutputStyle">
           <p>Welcome</p>
           <p>Hi, {props.userName}</p>
        </div>
    );
};

export default userOutput;