package exceptions;

public class InvalidDayException extends Exception
{
	private int day = 0;
	private int month = 0;
	private int year = 0;

	public InvalidDayException(int day)
	{
		this.day = day;
	}

	public InvalidDayException(int day,int month)
	{
		this.day = day;
		this.month = month;
	}

	public InvalidDayException(int day,int month,int year)
	{
		this.day = day;
		this.month = month;
		this.year = year;
	}

	public String toString()
	{
		if (month == 0)
			return "Day " + day + " is invalid";
		else if (year == 0)
			return "Day " + day + " is invalid for month " + month;
		else
			return "Day " + day + " is invalid for month " + month + " of year " + year;	
	}
}