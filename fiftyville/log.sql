-- Keep a log of any SQL queries you execute as you solve the mystery.
select description from crime_scene_reports;

select month from crime_scene_reports;

select year from crime_scene_reports;

select day, month, year from crime_scene_reports where day = 28 and month=7 and year = 2021;

select day, month, year, street from crime_scene_reports where day = 28 and month=7 and year = 2021 and street = 'Humphrey Street';

select id from crime_scene_reports where street = 'Humphrey Street' and day = 28 and month = 7 abd year = 2021;

select description from crime_scene_reports where id = 295;
--theft at 10,15 am
--3 witness at the bakery

select description from crime_scene_reports where id = 297;
--littering

select id, year, month, day, hour, minute from bakery_security_logs where day =28 and month=7 and year = 2021 and hour=10 and minute between 0 and 16;
--id
--258 10h8
--259 10h14
--260 10h16

select id, name, day, month, year, transcript from interviews where day = 28 and month = 7 and year = 2021;

--id name
--161 ruth ' look for camera footage from the parking lot of the bakery
--162 eugene ' before 10:15 withdraw from ATM at leggett street'
--163 raymound 'call for less than a minute - FLIGHT TO FIFTYVILLE AT 29 07 2021 and purchase of flight ticket'



select id, caller, receiver, duration, day, month, year from phone_calls where day = 28 and month = 7 and year = 2021;
--id
--221
--224
--233
--251
--254
--255
select name from people join bakery_security_logs on bakery_security_logs.license_plate = people.license_plate
where year = 2021 and month = 7 and day=28 and hour = 10 and minute between 25 and 25 and activity = 'exit';
--SUSPECTS:

--Vanessa |
--| Bruce   |
--| Barry   |
--| Luca    |
--| Sofia   |
--| Iman    |
--| Diana   |
--| Kelsey

SELECT name from people join bank_accounts on bank_accounts.person_id=people.id
join atm_transactions on atm_transactions.account_number = bank_accounts.account_number
where year = 2021 and month = 7 and day = 28 and atm_location = 'Leggett Street' and transaction_type='withdraw';
--bruce *
--diana *
--brooke
--kenny
--iman *
--luca *
--taylor
--benista

select name from people join passengers on passengers.passport_number = people.passport_number where passengers.flight_id = (select id from flights where year = 2021 and month = 7 and day = 29 and origin_airport_id = (select id from airports where city = 'Fiftyville') order by hour, minute limit 1);

--doris
--sofia
--bruce*
--edward
--kelsey
--kenny
--luca*

select name from people join phone_calls on phone_calls.caller = people.phone_number where year = 2021 an month = 7 and day = 28 and duration < 60;
-- sofia
--kelsey
--bruce --> thief
--kelsey
--taylor
--diana
--carina
--kenny
--benista

select city from airports where id = (select destination_airport_id from flights where year = 2021 and month = 7 and day = 29 and origin_airport_id = (select id from airports where city = 'Fiftyville')order by hour,minute limit 1);
--new york city

select phone_number from people where name = 'Bruce';
--(367) 555-5533
;
select name from people where phone_number = (select receiver from phone_calls where year = 2021 and month = 7 and day = 28 and duration <60 and caller = '(367) 555-5533');
-- robin