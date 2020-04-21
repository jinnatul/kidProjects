package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.fxml.FXML;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.DatePicker;
import javafx.stage.Stage;
import javafx.scene.Parent;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;

import java.sql.*;
import java.io.IOException;
import java.time.LocalDate;


public class PatientPanel {

    @FXML
    private TextField txtPId;

    @FXML
    private TextField txtPFirstName;

    @FXML
    private TextField txtLastName;

    @FXML
    private TextField txtphone;

    @FXML
    private TextField txtAge;

    @FXML
    private DatePicker txtDate;

    @FXML
    private TextField txtProblem;

    @FXML
    private TextField txtRoomNumber;

    @FXML
    private TextField txtCost;


    //Add Patient Code

    public void AddPatient(ActionEvent even)throws IOException{

        PreparedStatement prst = null;
        ResultSet rs = null;

        String PID = txtPId.getText();
        String PFirstName = txtPFirstName.getText();
        String PLastName = txtLastName.getText();
        String PAge = txtAge.getText();
        LocalDate PDate = txtDate.getValue();
        String Gender = "Male";
        String PPhone = txtphone.getText();
        String PProblem = txtProblem.getText();
        String RoomNo = txtRoomNumber.getText();
        String PCost = txtCost.getText();

        try{

            Class.forName("com.mysql.jdbc.Driver");
            Connection con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();

            String CheckQuery = "select PId from patient";

            prst = con.prepareStatement(CheckQuery);
            rs = prst.executeQuery();
            while (rs.next()){
                String Pid = rs.getString("PId");
                if(Pid.equals(PID)){
                    LoginMassageBox.display("Insert Status", "This Id Already Use So try to another Id...");
                }
            }

            stmt.executeUpdate("INSERT INTO patient VALUES ('"+PID+"','"+PFirstName+"','"+PLastName+"','"+PAge+"','"+PDate+"','"+Gender+"','"+PPhone+"','"+PProblem+"','"+RoomNo+"', '"+PCost+"')");

            LoginMassageBox.display("Insert Status", "Insert Successfully");
            con.close();

        }catch(Exception e){ System.out.println(e);}
    }




//Search code

    public void SearchPatient(ActionEvent even)throws IOException{

        Connection con = null;
        PreparedStatement prst = null;
        ResultSet rs = null;
        String Id = null, FirstName = null;
        Id = txtPId.getText();
       // FirstName = txtFirstName.getText();

        String query = "select PId, FirstName, LastName, Age, Date3, Gender,Phone, Problem, RId, Cost from patient where  PId = ?  ";

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
                String PFirstName = rs.getString("FirstName");
                String PLastName = rs.getString("LastName");
                String PAge = rs.getString("Age");
                Date DDate = rs.getDate("Date3");
                String Gender = rs.getString("Gender");
                String Phone = rs.getString("Phone");
                String PProblem = rs.getString("Problem");
                String RId = rs.getString("RId");
                String PCost = rs.getString("Cost");
                String datetxt = DDate.toString();

                txtPFirstName.setText(PFirstName);
                txtLastName.setText(PLastName);
                txtAge.setText(PAge);
                txtDate.setValue(LocalDate.parse(datetxt));
                txtphone.setText(Phone);
                txtProblem.setText(PProblem);
                txtRoomNumber.setText(RId);
                txtCost.setText(PCost);

            }

        }catch(Exception e){ System.out.println(e);}
    }



    // Update code


    public void UpdatePatientr(ActionEvent even)throws Exception{

        Connection con = null;
        PreparedStatement prst = null;
        ResultSet rs = null;
        String PId1 = txtPId.getText();

        String FirstName = txtPFirstName.getText();
        String LastName = txtLastName.getText();
        String Age = txtAge.getText();
        LocalDate DDate = txtDate.getValue();
        String Gender = "Male";
        String Phone = txtphone.getText();
        String Problem = txtProblem.getText();
        String RoomNumber = txtRoomNumber.getText();
        String Cost = txtCost.getText();
        String dateshow = DDate.toString();

        String query = "UPDATE patient set FirstName = ?, LastName = ?, Age = ?, Date3 = ?,Gender = ? ,Phone = ?, Problem = ?, RId = ?, Cost = ? where PId = ?";

        try{
            Class.forName("com.mysql.jdbc.Driver");
            con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();
            prst = con.prepareStatement(query);
            prst.setString(1,FirstName);
            prst.setString(2,LastName);
            prst.setString(3,Age);
            prst.setString(4,dateshow);
            prst.setString(5, Gender);
            prst.setString(6,Phone);
            prst.setString(7,Problem);
            prst.setString(8,RoomNumber);
            prst.setString(9,Cost);
            prst.setString(10,PId1);

            int i = prst.executeUpdate();
            if(i==1) {
                LoginMassageBox.display("UpDate Status", "UpDate Successfully");
            }
        }
        catch(Exception e){ System.out.println(e);}
    }






    //Delete code

    public void DeletePatient(ActionEvent even)throws Exception{

        Connection con = null;
        PreparedStatement prst = null;
        ResultSet rs = null;
        String PId = txtPId.getText();

        String query = "delete from patient where PId = ?";

        try{
            Class.forName("com.mysql.jdbc.Driver");
            con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();
            prst = con.prepareStatement(query);
            prst.setString(1,PId);
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



    // RoomTable Code

    public void RoomTable(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("RoomR.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 600));
        primaryStage.show();
    }

    // Back Code

    public void Back(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("ReceptionPanel.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 720, 500));
        primaryStage.show();
    }

}
