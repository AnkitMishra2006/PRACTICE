import TextField from "@mui/material/TextField";
import Button from "@mui/material/Button";
import { useState } from "react";
import "./SearchBox.css";
import { red } from "@mui/material/colors";
export default function SearchBox({ updateInfo }) {
  let [city, setcity] = useState("");
  let [error, setError] = useState(false);

  let API_URL = "https://api.openweathermap.org/data/2.5/weather";
  let API_KEY = import.meta.env.VITE_API_KEY;

  async function getWeatherInfo(city) {
    try {
      let geoResponse = await fetch(
        `http://api.openweathermap.org/geo/1.0/direct?q=${city}&appid=${API_KEY}`
      );
      let [geoJsonResponse] = await geoResponse.json();
      let { lat, lon } = geoJsonResponse;
      console.log("lat & lon: ", lat, lon);
      console.log(
        `fetching: ${API_URL}?lat=${lat}&lat=${lon}&appid=${API_KEY}`
      );
      let response = await fetch(
        `${API_URL}?lat=${lat}&lon=${lon}&appid=${API_KEY}&units=metric`
      );
      let jsonResponse = await response.json();
      console.log("JSON RESPONSE: ", jsonResponse);
      console.log(jsonResponse);
      let result = {
        city: city,
        temp: jsonResponse.main.temp,
        tempMin: jsonResponse.main.temp_min,
        tempMax: jsonResponse.main.temp_max,
        feelsLike: jsonResponse.main.feels_like,
        humidity: jsonResponse.main.humidity,
        weather: jsonResponse.weather[0].description,
      };
      console.log(result);
      return result;
    } catch (error) {
      throw error;
    }
  }

  let handleChange = (event) => {
    setcity(event.target.value);
  };

  let handleSubmit = async (event) => {
    try {
      event.preventDefault();
      console.log(city);
      setcity("");

      let newInfo = await getWeatherInfo(city);
      updateInfo(newInfo);

      // console.log(getGeoLoc(city));
    } catch (error) {
      setError(true);
    }
  };

  return (
    <div className="search-box">
      <form onSubmit={handleSubmit}>
        <TextField
          id="city"
          label="City Name"
          variant="outlined"
          onChange={handleChange}
          value={city}
          required
        />
        <br /> <br />
        <Button type="submit" variant="contained">
          Search
        </Button>
      </form>
      {error && <p style={{ color: "red" }}>No such place exists in our API</p>}
    </div>
  );
}
