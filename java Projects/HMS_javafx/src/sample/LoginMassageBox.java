package sample;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class LoginMassageBox {

    public static void display(String title, String massage){
        Stage window = new Stage();
        window.setTitle(title);
        window.setMinWidth(300);
        window.setMaxHeight(150);

        Label label = new Label();
        label.setText(massage);

        Button button = new Button("ok");
        button.setOnAction(e -> window.close());

        VBox layout = new VBox(5);
        layout.getChildren().addAll(label, button);
        layout.setAlignment(Pos.CENTER);

        Scene scene = new Scene(layout);
        window.setScene(scene);
        window.showAndWait();

    }
}
