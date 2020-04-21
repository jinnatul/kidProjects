package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class ReceptionPanel {

    //Room Code Reception
    public void Room(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("RoomR.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 600));
        primaryStage.show();
    }

    public void Patient(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("Patient.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 640));
        primaryStage.show();
    }

    //Finincial Code

    public void Financal(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("FinanceInfo.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 600));
        primaryStage.show();
    }

    //LogOut Code
    public void LogOut(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("AdminReceptionCheck.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1000, 600));
        primaryStage.show();
    }
}
