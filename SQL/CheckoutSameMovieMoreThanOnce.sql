--Find same user checkout the same movie more than once
CREATE COLUMN TABLE "IM_SERVICES"."TEST" (ID INTEGER, MOVIE NVARCHAR(20));

insert into "IM_SERVICES"."TEST" values (40, 'BBT');
insert into "IM_SERVICES"."TEST" values (14, '24');
insert into "IM_SERVICES"."TEST" values (14, 'BBT');
insert into "IM_SERVICES"."TEST" values (23, 'BBT');
insert into "IM_SERVICES"."TEST" values (25, '24');
insert into "IM_SERVICES"."TEST" values (40, 'BBT');
insert into "IM_SERVICES"."TEST" values (44, 'BBT');
insert into "IM_SERVICES"."TEST" values (14, '24');
insert into "IM_SERVICES"."TEST" values (14, 'TW');


SELECT ID, MOVIE
FROM "IM_SERVICES"."TEST"
GROUP BY ID, MOVIE
HAVING COUNT(*) > 1;