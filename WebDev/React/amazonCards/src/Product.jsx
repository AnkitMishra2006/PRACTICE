import "./Product.css";
import Price from "./Price.jsx";

function Product({ title, idx }) {
  let oldPrices = ["12,495", "11,900", "1,599", "599"];
  let newPrices = ["8,999", "9,199", "899", "278"];
  let description = [
    ["8000 DPI", "5 Programmable Buttons"],
    ["Intuitive Surface", "designed for iPad Pro"],
    ["Designed For iPad Pro", "Intuitive Surface"],
    ["WireLess", "Optical Orientation"],
  ];
  return (
    <div className="Product">
      <h4>{title}</h4>
      <p>{description[idx][0]}</p>
      <p>{description[idx][1]}</p>
      <Price oldPrice={oldPrices[idx]} newPrice={newPrices[idx]}></Price>
    </div>
  );
}

export default Product;
