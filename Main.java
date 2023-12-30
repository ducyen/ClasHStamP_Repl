import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class Main extends JFrame {

    private JButton button;

    public Main() {
        setTitle("Launch Application");
        setSize(300, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        button = new JButton("Launch Application");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                launchApplication();
            }
        });

        add(button);
    }

    private void launchApplication() {
        button.setEnabled(false); // Disable the button

        // Launch the target application
        try {
            Process process = new ProcessBuilder("./astah-com_linux/astah-run.sh", "").start();

            // Monitor the status of the launched application
            new Thread(() -> {
                try {
                    int exitCode = process.waitFor(); // Wait for the process to exit
                    if (exitCode == 0) {
                        // The application exited successfully
                        button.setEnabled(true); // Enable the button
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }).start();

        } catch (IOException e) {
            e.printStackTrace();
            button.setEnabled(true); // Enable the button in case of an error
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Main().setVisible(true);
            }
        });
    }
}
