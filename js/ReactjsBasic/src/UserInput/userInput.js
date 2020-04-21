import React from 'react';

const userInput = (props) => {

    const userInputStyle = {
        textAlign: "center",
        padding: "10px 100px"
    };

    return (
        <div style={userInputStyle}>
            <input type="text" onChange={props.onChanged} value={props.previousName}/>
        </div>
    );
};

export default userInput;