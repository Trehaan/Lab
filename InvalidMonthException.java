package exceptions;

public class InvalidMonthException extends Exception
{
	int month = 0;

	public InvalidMonthException(int month)
	{
		this.month = month;
	}

	public String toString()
	{
		return "Month " + month + " is invalid.";
	}
}

