-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Crime: 10:15
-- Interviewer: 3, mentions courtyard
-- SELECT * FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND street = "Chamberlin Street" AND day = 28;

-- 10 minute courtyard, Earlier in atm (fifer street), earliest flight out of fiftyville
-- SELECT transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28 AND transcript LIKE "%courthouse%";

-- SELECT * FROM courthouse_security_logs JOIN people ON courthouse_security_logs.license_plate = people.license_plate WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25;

-- SELECT people.name FROM atm_transactions JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number JOIN people ON bank_accounts.person_id = people.id WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street";

-- Flight ID: 36
-- SELECT flights.id, month, day, hour FROM flights JOIN airports ON flights.origin_airport_id = airports.id WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour

-- SELECT people.name FROM passengers JOIN people ON passengers.passport_number = people.passport_number WHERE flight_id = 36

-- Phone number: (577) 315-9633
-- SELECT * FROM phone_calls WHERE caller = "(367) 555-5533" AND year = 2020 AND month = 7 AND day = 28 AND duration < 60

SELECT * FROM people WHERE phone_number = "(375) 555-8161";
