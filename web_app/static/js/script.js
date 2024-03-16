let deviceCount = 0;

function addDevice() {
    deviceCount++;
    const inputContainer = document.getElementById('input-body');
    const newRow = document.createElement('tr');
    newRow.innerHTML = `
        <td><input type="number" name="voltage${deviceCount}" step="any" required></td>
        <td><input type="number" name="ampere${deviceCount}" step="any" required></td>
        <td><input type="text" name="device${deviceCount}" required></td>
    `;
    inputContainer.appendChild(newRow);
}

function predict() {
    const form = document.getElementById('prediction-form');
    const formData = new FormData(form);
    fetch('/predict', {
        method: 'POST',
        body: formData
    })
    .then(response => response.json())
    .then(data => {
        displayResult(data);
    });
}

function displayResult(data) {
    const resultDiv = document.getElementById('result');
    resultDiv.innerHTML = `
        <h2>Predicted Power:</h2>
        <p>${data.predicted_power}</p>
        <h2>Device Ranking:</h2>
        <ul>
            ${data.device_ranking.map(device => `<li>${device}</li>`).join('')}
        </ul>
    `;
}

function addRow() {
    var table = document.querySelector('#dataTable');
    var row = table.insertRow();
    row.innerHTML = `
        <td><input type="text" name="device"></td>
        <td><input type="text" name="voltage"></td>
        <td><input type="text" name="ampere"></td>
        <td><button type="button" onclick="removeRow(this)">Hapus Data</button></td>
    `;
}

function removeRow(btn) {
    var row = btn.parentNode.parentNode;
    row.parentNode.removeChild(row);
}
