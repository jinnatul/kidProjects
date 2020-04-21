package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.fxml.FXML;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class AdminPanel {

    //Doctor Code
    public void Doctor(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("Doctor.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 600));
        primaryStage.show();
    }

    //Staff Code
    public void Staff(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("Staff.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 600));
        primaryStage.show();
    }

    //Room Code
    public void Room(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("Room.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1080, 600));
        primaryStage.show();
    }


  //LogOut code
    public void LogOut(ActionEvent even) throws IOException {
        ((Node)even.getSource()).getScene().getWindow().hide();

        Stage primaryStage = new Stage();
        Parent root = FXMLLoader.load(getClass().getResource("AdminReceptionCheck.fxml"));
        primaryStage.setTitle("Hospital Management System");
        primaryStage.setScene(new Scene(root, 1000, 600));
        primaryStage.show();
    }
}
