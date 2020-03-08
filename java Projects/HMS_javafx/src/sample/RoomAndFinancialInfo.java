package sample;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;
import java.sql.*;

public class RoomAndFinancialInfo {
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

    //Search code

    public void SearchRoom(ActionEvent even)throws IOException {

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


    //Patient Table Code

    public void PatientTable(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("Patient.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 640));
        primaryStage.show();
    }



    //Back Code

    public void Backmain(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("ReceptionPanel.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 720, 500));
        primaryStage.show();
    }



}
