const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost:27017/customer', {useNewUrlParser: true}, (err)=>{
    if(!err){
        console.log('MongoDb connection successed') 
    }
    else{
        console.log("Error in Db connection : " + err)
    }
});

require('./employee.model');