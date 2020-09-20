package CreationalPattern.AbstractFactory;

abstract class AbstractFactory {
    public abstract Bank getBank(String bank);
    public abstract Loan getLoan(String loan);
}

class BankFactory extends AbstractFactory{
    public Bank getBank(String bank){
        if(bank == null) return null;
        if(bank.equalsIgnoreCase("CIBC")) return new CIBC();
        else if(bank.equalsIgnoreCase("BMO")) return new BMO();
        else if(bank.equalsIgnoreCase("TD")) return new TD();
        return null;
    }
    public Loan getLoan(String loan) { return null; }
}

class LoanFactory extends AbstractFactory{
    public Bank getBank(String bank){ return null; }

    public Loan getLoan(String loan){
        if(loan == null) return null;
        if(loan.equalsIgnoreCase("Home")) return new HomeLoan();
        else if(loan.equalsIgnoreCase("Business")) return new BussinessLoan();
        else if(loan.equalsIgnoreCase("Education")) return new EducationLoan();
        return null;
    }
}

