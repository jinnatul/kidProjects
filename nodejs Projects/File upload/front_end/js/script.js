/*$(document).ready (function(){
   //$('#update-form').hide();

    //var change = prompt('Change to:', '');
    $('.btn_update').click(function(){

        var id = $(this).attr('id');
        var show_name = $('show_name').val();
        console.log("ScriptJs: "+id);
        $.ajax({
            type: 'PUT',
            url: '/update/'+id,
            data: {show_name:show_name},
            success: function(data){
                console.log(data);
                //window.location = "/edit";
               // $('#update-form').show(data);
            }
        })

    })
   

}); */

