$(function() {
    let apiURL = "https://corona-bd.herokuapp.com/district"

    $.get(apiURL, function() {})
        .done(function(res) {
            $('#details').html("<h3>Total Infected (COVID-19): " + res["total_infected"] + "</h3>" + 
                                "Update Time: " + res["updated_on"])
            mapMaker(res);
        });
})


function mapMaker(res) {
    console.log(res["data"])
    var tooltip = document.querySelector('#each_District');
    var svgObject = document.getElementById('district_Map').contentDocument;
    var svgSelector = svgObject.querySelector('.country');

    let dataMAP = {};

    for (let index = 0; index < res["data"].length; index++) {
        let name = res["data"][index]["name"];
        name = name.replace("Dhaka City", "Dhaka")
        name = name.replace("Munshigonj", "Munshiganj")
        name = name.replace("Laksmipur", "Lakshmipur")
        name = name.replace("B. Baria", "Brahmanbaria")
        name = name.replace("Moulovi Bazar", "Moulvibazar")
        name = name.replace("Potuakhali", "Patuakhali")
        name = name.replace("Hobiganj", "Habiganj")
        name = name.replace("Panchagar", "Panchagarh")
        name = name.replace("Cox’s bazar", "CoxsBazar")
        name = name.replace("Narshingdi", "Narsingdi")
        dataMAP[name] = res["data"][index]["count"]

        //set color on Each district base on affected count
        let disName = "#" + name;
        if (name === "Dhaka (District)") continue;
        if (res["data"][index]["count"] > 0 && res["data"][index]["count"] <= 20) {
            $(svgObject.querySelector(disName)).css("fill", "#e57373");
        }
        else if (res["data"][index]["count"] > 20 && res["data"][index]["count"] <= 50) {
            $(svgObject.querySelector(disName)).css("fill", "#ef5350");
        }
        else if (res["data"][index]["count"] > 50 && res["data"][index]["count"] <= 100) {
            $(svgObject.querySelector(disName)).css("fill", "#f44336");
        }
        else if (res["data"][index]["count"] > 100) {
            $(svgObject.querySelector(disName)).css("fill", "#d50000");
        }
    }
    
    $tooltip = $('#each_District');
    $(svgSelector).mouseover(function(event) {
        var currentLocation = dataMAP[event.target.id];
        $tooltip.html(event.target.id);
        if(currentLocation!==undefined){
            $tooltip.html(event.target.id + ": "+ currentLocation);
        }
        else {
            $tooltip.html(event.target.id + ": 0");
        }

        tooltip.style.display = 'block';
        $(each_District).css('top', event.pageY + 100);
        $(each_District).css('left', event.pageX - 10);
    });
    $(svgSelector).mouseleave(function(event) {
        tooltip.style.display = 'none';
    });
}