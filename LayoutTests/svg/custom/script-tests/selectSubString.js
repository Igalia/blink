var svgNS = "http://www.w3.org/2000/svg";

var svgRoot = document.createElementNS(svgNS, "svg");
document.documentElement.appendChild(svgRoot);

var svgText = document.createElementNS(svgNS, "text");
svgText.style.fontFamily = "Ahem";
svgText.style.fontSize = "20px";
svgText.appendChild(document.createTextNode("abc"));
svgRoot.appendChild(svgText);

shouldThrow("svgText.selectSubString(-1, 0)", "'IndexSizeError: Index or size was negative, or greater than the allowed value.'");
shouldNotThrow("svgText.getSubStringLength(0, -1)");
shouldThrow("svgText.getSubStringLength(3, 0)", "'IndexSizeError: Index or size was negative, or greater than the allowed value.'");

// cleanup
document.documentElement.removeChild(svgRoot);

var successfullyParsed = true;
