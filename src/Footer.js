import React from 'react';

import {
    Box,
    Container,
    Row,
    Column,
    FooterLink,
    Heading,
  } from "./FooterStyles";


const Footer = () => {
    return (
      <Box>
        <h1 style={{ color: "white", 
                     textAlign: "center", 
                     marginTop: "-50px" }}>
          Remote Presence Robot
        </h1>
        <Container>
          <Row>
            <Column>
              <Heading>About Us</Heading>
              <FooterLink href="#">Aim</FooterLink>
              <FooterLink href="#">Vision</FooterLink>
              <FooterLink href="#">Testimonials</FooterLink>
            </Column>
            <Column>
              <Heading>Contact Us</Heading>
              <FooterLink href="#">Noah Trinite</FooterLink>
              <FooterLink href="#">George Tatge</FooterLink>
              <FooterLink href="#">Dylan Sloan</FooterLink>
              <FooterLink href="#">Anna Furrow</FooterLink>
              <FooterLink href="#">James Perdue</FooterLink>
              <FooterLink href="#">Joshua Odeyemi</FooterLink>
              <FooterLink href="#">Christopher Lyons</FooterLink>
            </Column>
          </Row>
        </Container>
      </Box>
    );
  };
  export default Footer;