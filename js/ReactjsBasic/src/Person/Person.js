import React from 'react';
import './Person.css'

const Person = (props) => {
    return (
        <div className="person">
            <p onClick={props.click}>My name is {props.name} and age {props.age}</p>
            <p>{props.children}</p>
            <input type="text" onChange={props.changed} value={props.name}/>
        </div>
    )
};

export default Person;