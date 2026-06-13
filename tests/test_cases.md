# Test Cases

## TC01 Pizza Order Success

Input:
order pizza 2 "extra cheese"

Expected:
SUCCESS
ETA 15

---

## TC02 Burger Order Success

Input:
order burger 1 "no onion"

Expected:
SUCCESS
ETA 10

---

## TC03 Drinks Order Success

Input:
order coke 3 "cold"

Expected:
SUCCESS
ETA 3

---

## TC04 Invalid Quantity

Input:
order pizza 0 "extra cheese"

Expected:
ERROR

---

## TC05 Wrong Item

Input:
order burger 1

Sent to pizza_server

Expected:
ERROR

---

## TC06 Server Down

Stop pizza_server

Expected:
Connection Refused

---

## TC07 Malformed Packet

Expected:
Malformed Packet Error

---

## TC08 Multiple Orders

Pizza
Burger
Coke

Expected:
Order Summary Generated

---

## TC09 Timeout

Expected:
Timeout Error

---

## TC10 Summary Display

Expected:
All Responses Collected
