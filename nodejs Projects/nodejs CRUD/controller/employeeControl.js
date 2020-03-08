const express = require('express');
var router = express.Router();
const mongoose = require('mongoose');
const Employee = mongoose.model('Employee');

/* Show Employee List */
router.get('/list', (req, res) => {
    Employee.find((err, docs) => {
        if(!err){
            res.render("employee/list", {
                list: docs
            });
        }
        else{
            console.log("Error message List Show Time: " + err);
        }
    });
});

/* Error check and Show */
function handleValidationError(err, body){
    for (field in err.errors){
        switch(err.errors[field].path){
            case 'fullName':
                body['fullNameError'] = err.errors[field].message;
                break;
            
            case 'email':
                body['emailError'] = err.errors[field].message;
                break;
            default:
                break;
        }
    }
}


/* Insert Information */
router.get('/', (req, res) => {
    res.render("employee/AddOrEdit", {
        viewTitle: "Insert Employees"
    });
});

router.post('/', (req, res) => {
    if(req.body._id == '')
        InsertInfo(req, res);
    else
        UpdateInfo(req, res);
});

function InsertInfo(req, res){
    var employee = new Employee();
    employee.fullName = req.body.fullName;
    employee.email = req.body.email;
    employee.mobile = req.body.mobile;
    employee.city = req.body.city;
    employee.save((err, doc) => {
        if(!err){
            res.redirect('employee/list');
        }
        else{
            if(err.name == 'ValidationError'){
                handleValidationError(err, req.body);
                res.render("employee/AddOrEdit", {
                    viewTitle: "Insert Employee",
                    employee: req.body
                });
            }
            else
                console.log("Error message Insert Time: " + err);
        }
    });
}


/* Update Information */

router.get('/:id', (req, res) => {
    Employee.findById(req.params.id, (err, doc) => {
        if(!err){
            res.render("employee/AddOrEdit", {
                viewTitle: "Update Employee",
                employee: doc
            });
        }
    });
});

function UpdateInfo(req, res){
    Employee.findOneAndUpdate({_id: req.body._id}, req.body, {new: true}, (err, doc) =>{
        if(!err){
            res.redirect('employee/list');
        }
        else{
            if(err.name == 'ValidationError'){
                handleValidationError(err, req.body);
                res.render("employee/AddOrEdit", {
                    viewTitle: 'Update Employee',
                    employee: req.body
                });
            }
            else{
                console.log("Error message Update Time: " + err);
            }
        }
    });
}

/* Delete Information */

router.get('/delete/:id', (req, res) =>{
    Employee.findByIdAndRemove(req.params.id, (err, doc) =>{
        if(!err){
            res.redirect('/employee/list');
        }
        else{
            console.log("Error message Delete Time: " + err);
        }
    });
});



module.exports = router;