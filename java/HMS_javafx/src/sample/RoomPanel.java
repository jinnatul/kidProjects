package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.*;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import java.io.*;
import java.sql.*;
import java.time.LocalDate;



public class RoomPanel {

    @FXML
    private TextField txtRoomNo;

    @FXML
    private TextField txtProblemType;

    @FXML
    private TextField txtDoctorId;

    @FXML
    private TextField txtDoctorName;

    @FXML
    private TextField txtStaffId;

    @FXML
    private TextField txtStaffName;

    @FXML
    private TextField txtStaffWorkName;

    //Add code

    public void AddRoom(ActionEvent even)throws IOException {

        PreparedStatement prst = null;
        ResultSet rs = null;

        String RId = txtRoomNo.getText();
        String RProblemType = txtProblemType.getText();
        String RDoctorId = txtDoctorId.getText();
        String RDoctorName = txtDoctorName.getText();
        String RStaffId = txtStaffId.getText();
        String RStaffName = txtStaffName.getText();
        String RStaffWorkType = txtStaffWorkName.getText();

        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();

            String CheckQuery = "select RId from room";

            prst = con.prepareStatement(CheckQuery);
            rs = prst.executeQuery();
            while (rs.next()){
                String Rid = rs.getString("RId");
                if(Rid.equals(RId)){
                    LoginMassageBox.display("Insert Status", "This Id Already Use So try to another Id...");
                }
            }
            //System.out.println(Gender);

            stmt.executeUpdate("INSERT INTO room VALUES ('" + RId + "','" + RProblemType + "','" + RDoctorId + "','" + RDoctorName + "','" + RStaffId + "','" + RStaffName + "','" + RStaffWorkType + "')");


            LoginMassageBox.display("Insert Status", "Insert Successfully");


            con.close();

        }catch(Exception e){ System.out.println(e);}
    }



    //Search code

    public void SearchRoom(ActionEvent even)throws IOException{

        Connection con = null;
        PreparedStatement prst = null;
        ResultSet rs = null;
        String Id = null, FirstName = null;
        Id = txtRoomNo.getText();
        //FirstName = txtFirstName.getText();

        String query = "select RId, ProblemType, DId, DoctorName, SId, StaffName, StaffWorkType from room where  RId = ?  ";

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
                String ProblemType = rs.getString("ProblemType");
                String DId = rs.getString("DId");
                String DoctorName = rs.getString("DoctorName");
                String SId = rs.getString("SId");
                String StaffName = rs.getString("StaffName");
                String StaffWorkType = rs.getString("StaffWorkType");

                txtProblemType.setText(ProblemType);
                txtDoctorId.setText(DId);
                txtDoctorName.setText(DoctorName);
                txtStaffId.setText(SId);
                txtStaffName.setText(StaffName);
                txtStaffWorkName.setText(StaffWorkType);

            }

        }catch(Exception e){ System.out.println(e);}
    }




    // Update code


    public void UpdateRoom(ActionEvent even)throws Exception{

        Connection con = null;
        PreparedStatement prst = null;
        ResultSet rs = null;
        String RId = txtRoomNo.getText();
        String ProblemType = txtProblemType.getText();
        String DId = txtDoctorId.getText();
        String DoctorName = txtDoctorName.getText();
        String SId = txtStaffId.getText();
        String StaffName = txtStaffName.getText();
        String StaffWorkType = txtStaffWorkName.getText();


        String query = "UPDATE room set ProblemType = ?, DId = ?, DoctorName = ?, SId = ?,StaffName = ? ,StaffWorkType = ? where RId = ?";

        try{
            Class.forName("com.mysql.jdbc.Driver");
            con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();
            prst = con.prepareStatement(query);
            prst.setString(1,ProblemType);
            prst.setString(2,DId);
            prst.setString(3,DoctorName);
            prst.setString(4,SId);
            prst.setString(5, StaffName);
            prst.setString(6,StaffWorkType);
            prst.setString(7,RId);

            int i = prst.executeUpdate();
            if(i==1) {
                LoginMassageBox.display("UpDate Status", "UpDate Successfully");
            }
        }
        catch(Exception e){ System.out.println(e);}
    }





    //Delete code

    public void DeleteRoom(ActionEvent even)throws Exception{

        Connection con = null;
        PreparedStatement prst = null;
        ResultSet rs = null;
        String RId = txtRoomNo.getText();

        String query = "delete from room where RId = ?";

        try{
            Class.forName("com.mysql.jdbc.Driver");
            con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/admin?useSSL=false","root","morol");

            Statement stmt=con.createStatement();
            prst = con.prepareStatement(query);
            prst.setString(1,RId);
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



    //DoctorTable Code

    public void DoctorTable(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("Doctor.fxml"));
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
