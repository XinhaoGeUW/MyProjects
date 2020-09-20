package admin;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class StudentData {
    private final StringProperty ID;
    private final StringProperty FirstName;
    private final StringProperty LastName;
    private final StringProperty Email;
    private final StringProperty Date;

    public StudentData(String id, String fname, String lname, String email, String date) {
        ID = new SimpleStringProperty(id);
        FirstName = new SimpleStringProperty(fname);
        LastName = new SimpleStringProperty(lname);
        Email = new SimpleStringProperty(email);
        Date = new SimpleStringProperty(date);
    }


    public String getID() {
        return ID.get();
    }

    public StringProperty IDProperty() {
        return ID;
    }

    public void setID(String ID) {
        this.ID.set(ID);
    }

    public String getFirstName() {
        return FirstName.get();
    }

    public StringProperty firstNameProperty() {
        return FirstName;
    }

    public void setFirstName(String firstName) {
        this.FirstName.set(firstName);
    }

    public String getLastName() {
        return LastName.get();
    }

    public StringProperty lastNameProperty() {
        return LastName;
    }

    public void setLastName(String lastName) {
        this.LastName.set(lastName);
    }

    public String getEmail() {
        return Email.get();
    }

    public StringProperty emailProperty() {
        return Email;
    }

    public void setEmail(String email) {
        this.Email.set(email);
    }

    public String getDate() {
        return Date.get();
    }

    public StringProperty dateProperty() {
        return Date;
    }

    public void setDate(String date) {
        this.Date.set(date);
    }
}
