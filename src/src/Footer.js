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
       
        <Container>
          <Row>
            <Column></Column>
            <Column>
              <Heading>Contact Us</Heading>
            </Column>
          </Row>
              
          <Row>
              <FooterLink href="mailto:ntrinite@students.kennesaw.edu">Noah Trinite</FooterLink>
              <FooterLink href="mailto:gtatge@students.kennesaw.edu">George Tatge</FooterLink>
              <FooterLink href="mailto:dsloan6@students.kennesaw.edu">Dylan Sloan</FooterLink>
              <FooterLink href="mailto:afurrow@students.kennesaw.edu">Anna Furrow</FooterLink>
              <FooterLink href="mailto:jperdu13@students.kennesaw.edu">James Perdue</FooterLink>
              <FooterLink href="mailto:aodeyem2@students.kennesaw.edu">Joshua Odeyemi</FooterLink>
              <FooterLink href="mailto:clyons10@students.kennesaw.edu">Christopher Lyons</FooterLink>
          </Row>
        </Container>
      </Box>
    );
  };
  export default Footer;