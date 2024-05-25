Select firstName, lastName,city,state
from Person left join Address ON
Person.personId =Address.personId  ;