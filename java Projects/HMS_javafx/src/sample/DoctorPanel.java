package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.fxml.FXML;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.Stage;
import javafx.scene.Parent;

import java.sql.*;
import java.io.IOException;
import java.time.LocalDate;

public class DoctorPanel {

    @FXML
    private TextField txtDoctorId;

    @FXML
    private TextField txtFirstName;

    @FXML
    private TextField txtLastName;

    @FXML
    private TextField txtAge;

    @FXML
    private DatePicker txtDate;

    @FXML
    private TextField txtPhone;

    @FXML
    private RadioButton gender;


    @FXML
    private TextField txtSpecialist;

    @FXML
    private TextField txtsalary;

    @FXML
    private Label showGender;


//Add code

    public void AddDoctor(ActionEvent even)throws IOException{

        PreparedStatement prst = null;
        ResultSet rs = null;

        String DId = txtDoctorId.getText();
        String DFirstName = txtFirstName.getText();
        String DLastName = txtLastName.getText();
        String DAge = txtAge.getText();
        LocalDate DDate = txtDate.getValue();
        String DPhone = txtPhone.getText();

        //String Gender = null, GenderF = null;
        //Gender = gender.getText();
        //GenderF = genderF.getText();
        //Female = txtfemale.getText();

        String DSpecialist = txtSpecialist.getText();
        String DSalary = txtsalary.getText();

        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();

            String CheckQuery = "select DId from doctor";

            prst = con.prepareStatement(CheckQuery);
            rs = prst.executeQuery();
            while (rs.next()){
                String Did = rs.getString("DId");
                if(Did.equals(DId)){
                    LoginMassageBox.display("Insert Status", "This Id Already Use So try to another Id...");
                }
            }
            //System.out.println(Gender);

            stmt.executeUpdate("INSERT INTO doctor VALUES ('" + DId + "','" + DFirstName + "','" + DLastName + "','" + DAge + "','" + DDate + "','" + DPhone + "','" + "Male" + "','" + DSpecialist + "', '" + DSalary + "')");


            LoginMassageBox.display("Insert Status", "Insert Successfully");


         con.close();

        }catch(Exception e){ System.out.println(e);}
    }

//Search code

    public void SearchDoctor(ActionEvent even)throws IOException{

        Connection con = null;
        PreparedStatement prst = null;
        ResultSet rs = null;
        String Id = null, FirstName = null;
        Id = txtDoctorId.getText();
        FirstName = txtFirstName.getText();

        String query = "select DId, FirstName, LastName, Age, Date1, Phone, Gender, Specialist, Salary from doctor where  DId = ?  ";

        try{
            Class.forName("com.mysql.jdbc.Driver");
            con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();
            prst = con.prepareStatement(query);
            prst.setString(1,Id);
            //prst.setString(2,FirstName);
            rs = prst.executeQuery();

            while(rs.next()){

                //    String DId = rs.getString("DId");
                String DFirstName = rs.getString("FirstName");
                String DLastName = rs.getString("LastName");
                String DAge = rs.getString("Age");
                Date DDate = rs.getDate("Date1");
                String DPhone = rs.getString("Phone");
                String Gender1 = rs.getString("Gender");
                String DSpecialist = rs.getString("Specialist");
                String DSalary = rs.getString("Salary");
                String datetxt = DDate.toString();

                txtFirstName.setText(DFirstName);
                txtLastName.setText(DLastName);
                txtAge.setText(DAge);
                txtDate.setValue(LocalDate.parse(datetxt));
                txtPhone.setText(DPhone);
                showGender.setText(Gender1);
                txtSpecialist.setText(DSpecialist);
                txtsalary.setText(DSalary);

            }

        }catch(Exception e){ System.out.println(e);}
    }


    // Update code


    public void UpdateDoctor(ActionEvent even)throws Exception{

        Connection con = null;
        PreparedStatement prst = null;
        ResultSet rs = null;
        String DId1 = txtDoctorId.getText();

        String DFirstName = txtFirstName.getText();
        String DLastName = txtLastName.getText();
        String DAge = txtAge.getText();
        LocalDate DDate = txtDate.getValue();
        String DPhone = txtPhone.getText();
        String Gender = "Male";
        String DSpecialist = txtSpecialist.getText();
        String DSalary = txtsalary.getText();
        String dateshow = DDate.toString();

        String query = "UPDATE doctor set FirstName = ?, LastName = ?, Age = ?, Date1 = ?,Phone = ? ,Gender = ?, Specialist = ?, Salary = ? where DId = ?";

        try{
            Class.forName("com.mysql.jdbc.Driver");
            con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();
            prst = con.prepareStatement(query);
            prst.setString(1,DFirstName);
            prst.setString(2,DLastName);
            prst.setString(3,DAge);
            prst.setString(4,dateshow);
            prst.setString(5, DPhone);
            prst.setString(6,Gender);
            prst.setString(7,DSpecialist);
            prst.setString(8,DSalary);
            prst.setString(9,DId1);

            int i = prst.executeUpdate();
            if(i==1) {
                LoginMassageBox.display("UpDate Status", "UpDate Successfully");
            }
        }
        catch(Exception e){ System.out.println(e);}
    }


  //Delete code

    public void DeleteDoctor(ActionEvent even)throws Exception{

        Connection con = null;
        PreparedStatement prst = null;
        ResultSet rs = null;
        String DId = txtDoctorId.getText();

        String query = "delete from doctor where DId = ?";

        try{
            Class.forName("com.mysql.jdbc.Driver");
            con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();
            prst = con.prepareStatement(query);
            prst.setString(1,DId);
            int i = prst.executeUpdate();
            if(i==1)
            LoginMassageBox.display("Delete Status", "Delete Successfully");

        }
        catch(Exception e){ System.out.println(e);}
    }

    //Back Code

    public void Backmain(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("AdminPanel.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 720, 500));
        primaryStage.show();
    }



    //RoomTable Code

    public void RoomTable(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("Room.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 600));
        primaryStage.show();
    }


    //StaffTable Code

    public void StaffTable(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("Staff.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 600));
        primaryStage.show();
    }

}
