
# Installation

This application aims to predict electricity bills based on user input data regarding voltage, current and electrical devices used. This application uses the Random Forest Regression model to predict and rank the contribution of each device to electricity bills.


## Application installation Instructions (Locally)

Make sure Python is installed on your system. You can download Python from [its official website](https://www.python.org/downloads/). Clone this repository into your local directory:

```bash
  git clone https://github.com/ridwanmahendra/skilvul.git
```

Go to the application directory:

```bash
  cd web_app/
```

Install all required dependencies by running the following command:

```bash
  pip install -r requirements.txt
```

Once the installation is complete, run the application by running the command:

```bash
  python app.py
```
## Run Application

* Open a web browser and navigate to the address [http://127.0.0.1:5000/](http://127.0.0.1:5000/) to access the application.

* On the main page, enter the electricity rate per kWh and the  (V), ampere (A) and electrical device data you want to predict.

* Click the "Predict" button to see the electricity bill prediction results and device contribution ranking.

* To exit the application, close the terminal or press `Ctrl+C` in the terminal where the application is running.

## Notes

Make sure to have valid input data that conforms to the format expected by the application. Apart from that, make sure to provide electricity rates that are in accordance with the rates applicable in your area.

If you experience any problems or have questions, please feel free to contact [Ridwan Mahenra] at [ridwanmahenra@gmail.com].

Enjoy using the application!
## Screenshots

![App Screenshot](https://raw.githubusercontent.com/ridwanmahendra/skilvul/main/Screenshoot/Screenshot%202024-03-16%20at%2023.31.40.png)

