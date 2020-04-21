var mongoose = require('mongoose');
var Schema = mongoose.Schema;

detailSchema = new Schema( {
	p_name: String,
	p_category: String,
	p_price: String,
	p_image: String
}),
Detail = mongoose.model('detail', detailSchema);

module.exports = Detail;