import react from "react";
import Footer from "./Footer";
import robotlogo from "./robotlogo.png";
import "./Home.css"


function Home() {
    return(
        <>
            <h1 className="catchphrase">Be somewhere you can't!</h1>
            <div className="image-container">   
                <img src={robotlogo} className="robotlogo" alt="logo" />
            </div>
            <br/>
            <h2 className="h2">Login to connect to a robot!</h2>
            <Footer />
        </>
    );
}

export default Home;