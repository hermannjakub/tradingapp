import streamlit as st
import requests

# App title on the panel
st.title("Stock Dashboard")

# Panel button
if st.button("Download current prices"):
    try:
        # Python submits a request to the C++ server.
        odpowiedz = requests.get("http://localhost:8080/api/price")
        dane = odpowiedz.json()  # Translation from json in cpp to the dictionary in python.

        # Showing a green text on the screen
        st.success(f"Recieved the data! Product: {dane['symbol']}, Price: {dane['price']} USD")

    except Exception as e:
        # If the server is not available, show an error message.
        st.error("Unable to connect to C++ server. Make sure it works!")