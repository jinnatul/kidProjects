var express = require('express');
var multer = require('multer'),
bodyParser = require('body-parser'),
path = require('path');
var mongoose = require('mongoose');
var Detail = require('./models/detail');

/*var upload = multer({ dest: 'uploads/' });*/
mongoose.connect('mongodb://localhost:27017/customer', { useMongoClient: true });


var upload = multer({storage: multer.diskStorage({

  destination: function (req, file, callback) 
  { callback(null, './uploads');},
  filename: function (req, file, callback) 
  { callback(null, file.fieldname +'-' + Date.now()+path.extname(file.originalname));}

}),

fileFilter: function(req, file, callback) {
  var ext = path.extname(file.originalname)
  console.log("ext " + ext);
  if (ext !== '.png' && ext !== '.jpg' && ext !== '.gif' && ext !== '.jpeg') {
    //return callback(/*res.end('Only images are allowed')*/ null, false)
    return req.redirect('/');
  }
  callback(null, true)
}
});

var app = new express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
app.use(express.static(__dirname + '/front_end')); //Access javascript file
app.use(express.static('uploads'));

app.get('/', function(req, res){
  Detail.find({}, function(err,data){
    if(err){
      console.log(err);
    }else{
      res.render('index',{data:data});
    }
  })
  
});

app.post('/', upload.any(), function(req,res){
  
  console.log("req.body"); //form fields
  console.log(req.body);
  console.log("req.file");
  console.log(req.files); //form files
  
  console.log(req.body.p_price);
  if(!req.body && !req.files){
    res.json({success: false});
  } else {    
    var c;
    Detail.findOne({},function(err,data){
      /*
      console.log("into detail");

      if (data) {
        console.log("if");
        c = data.unique_id + 1;
      }else{
        c=1;
      }
*/
      var detail = new Detail({
        p_name: req.body.p_name,
        p_category: req.body.p_category,
        p_price: req.body.p_price,
        p_image: req.files[0].filename,
      });

      detail.save(function(err, Person){
        if(err)
          console.log(err);
        else{
          console.log("Save one");
          res.redirect('/');
        }
      });

    }).sort({_id: -1}).limit(1);

  }
});


/* Data get and send another Edit page */

app.get('/update/:id', function(req, res){
  //console.log("id : " + req.param.id);
 // const data = req.body; 
 var id = req.params.id;
 /*Detail.findOne({'_id':id}, function(err,data){
   if(err){
     console.log(err);
   }else{
    // res.render('index',{data:data});
    res.send(data);
   }
 })*/
Detail.findById(id, function(err,data){
   if(err){
     console.log(err);
   }else{
   //  res.render('edit',{edit_data:data});
     //res.send(data);
     res.render('edit',{data:data});
   }
 })
 
 // res.send('Response: '+id);

});


/* Data update from Edit page */

app.post('/update', upload.any(), function(req,res){

  
  //console.log("id "+ req.body.p_id);
  //console.log("id "+ req.files[0].filename);
  console.log(req.body);
 
  var updateValue = { $set: {p_name: req.body.p_name, p_category: req.body.p_category, p_price: req.body.p_price, p_image: req.files[0].filename } };
  console.log("UpdateValue " + updateValue);
  Detail.findOneAndUpdate({_id: req.body.p_id}, updateValue, {new: true}, (err, doc) =>{
    if(!err){
        res.redirect('/');
    }
    else{
      console.log("Update one");
      res.redirect('/');
    }
      
  })
});







var router = express.Router();

/* Update Information 

router.get('/update/:id', (req, res) => {
 console.log(req.params.id);
 
 Detail.findById(req.params.id, (err, doc) => {
  if(!err){
      console.log(doc._id);
  }
});

});*/




app.post('/delete',function(req,res){

   Detail.findByIdAndRemove(req.body.prodId,function(err, data) {

    console.log("Delete :" + req.body.p_image);

   })

   /* Need delete from folder */
   //var filePath = req.body.p_image; 
   //fs.unlinkSync(filePath);

  res.redirect('/');
});

var port = 2008;
app.listen( port, function(){ 
  
  console.log('listening on port '+port); 

});
