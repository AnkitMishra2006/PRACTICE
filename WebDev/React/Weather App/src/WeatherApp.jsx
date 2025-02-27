import SearchBox from "./SearchBox";
import InfoBox from "./InfoBox";
import { useState } from "react";

export default function WeatherApp() {
  let styles = {
    textAlign: "center",
  };
  let [weatherinfo, setWeatherinfo] = useState({
    city: "Delhi",
    feelsLike: 20.79,
    humidity: 60,
    temp: 21.06,
    tempMax: 21.06,
    tempMin: 21.06,
    weather: "haze",
  });

  let updateInfo = (newInfo) => {
    setWeatherinfo(newInfo);
  };

  return (
    <div style={styles}>
      <h1>Weather app</h1>
      <SearchBox updateInfo={updateInfo}></SearchBox>
      <InfoBox info={weatherinfo}></InfoBox>
    </div>
  );
}
