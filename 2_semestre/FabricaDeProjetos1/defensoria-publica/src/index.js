import * as React from "react";
import * as ReactDOM from "react-dom/client";
import {
  createBrowserRouter,
  RouterProvider,
} from "react-router-dom";
import "./Style/index.css";
import App from "./App";
import Landing from "./Pages/Landing";

function Root() {
  const [suburb, setSuburb] = React.useState(null);
  const [city, setCity] = React.useState(null);

  const router = createBrowserRouter([
    {
      path: "/home",
      element: <App city={city} suburb={suburb}/>,
    },
    {
      path: "/",
      element: <Landing setSuburb={setSuburb} setCity={setCity} city={city}/>,
    },
  ]);

  return <RouterProvider router={router} />;
}

ReactDOM.createRoot(document.getElementById("root")).render(
  <React.StrictMode>
    <Root />
  </React.StrictMode>
);
