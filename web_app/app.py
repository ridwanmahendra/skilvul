from flask import Flask, render_template, request
import pandas as pd
from joblib import load

app = Flask(__name__)

# Load trained model
model = load('model.pkl')

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/predict', methods=['POST'])
def predict():
    if request.method == 'POST':
        # Ambil nilai input dari form
        voltages = request.form.getlist('voltage')
        amperes = request.form.getlist('ampere')
        devices = request.form.getlist('device')
        electricity_rate_per_kWh = float(request.form['electricity-rate'])

        # Lakukan prediksi untuk setiap perangkat
        predictions = []
        total_power_consumption = 0
        for voltage, ampere in zip(voltages, amperes):
            voltage = float(voltage)
            ampere = float(ampere)
            power = model.predict([[voltage, ampere]])
            predictions.append(power[0])
            total_power_consumption += power[0]

        # Hitung kontribusi masing-masing perangkat
        device_contributions = [power / total_power_consumption for power in predictions]
        
        # Hitung tagihan listrik
        electricity_bill = total_power_consumption * electricity_rate_per_kWh


        # Gabungkan hasil prediksi dengan data perangkat
        results = list(zip(devices, predictions, device_contributions))

        # Urutkan berdasarkan kontribusi perangkat
        results.sort(key=lambda x: x[2], reverse=True)

        return render_template('result.html', results=results, electricity_bill=electricity_bill)

if __name__ == '__main__':
    app.run(debug=True)
