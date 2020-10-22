const league_id = 2021;
const token = /* get your token api from https://www.football-data.org/ */  ;
const base_url = "https://api.football-data.org/v2/";
const standing_url = `${base_url}competitions/${league_id}/standings`;
const team_url = `${base_url}teams/`;

const fetchApi = (url) => {
  return fetch(url, {
    mode: "cors",
    headers: { "X-Auth-Token": token },
  });
};

function status(response) {
  if (response.status !== 200) {
    console.log("Error : " + response.status);
    return Promise.reject(new Error(response.statusText));
  } else {
    return Promise.resolve(response);
  }
}
function json(response) {
  return response.json();
}

function error(error) {
  console.log("Error : " + error);
}

function getStandings() {
  fetchApi(standing_url)
    .then(status)
    .then(json)
    .then(function (data) {
      console.log(data);
      standingsHTML(data);
    })
    .catch(error);
}

function getMatch() {
  const MatchUrl = "https://api.football-data.org/v2/competitions/2021/matches";
  fetchApi(MatchUrl)
    .then(status)
    .then(json)
    .then((data) => {
      matchComponent(data);
    });
}

function standingsHTML(data) {
  let standingsHTML = `
              <table style="font-size:12px;" class="striped">
                <thead>
                  <tr>
                    <th colspan="3">Club</th>
                    <th>MP</th>
                    <th>W</th>
                    <th>D</th>
                    <th>L</th>
                    <th>Pts</th>
                  </tr>
                </thead>
                <tbody>
          `;
  data.standings["0"].table.forEach(function (item) {
    standingsHTML += `
                  <tr>
                    <td>${item.position}</td>
                    <td><a href="./team.html?id=${item.team.id}"><img style="width:25px;" src="${item.team.crestUrl}"></a></td>
                    <td><a href="./team.html?id=${item.team.id}">${item.team.name}</a></td>
                    <td>${item.playedGames}</td>
                    <td>${item.won}</td>
                    <td>${item.draw}</td>
                    <td>${item.lost}</td>
                    <td>${item.points}</td>
                  </tr>
          `;
  });
  standingsHTML += `</tbody>
              </table>`;
  document.getElementById("standings").innerHTML = standingsHTML;
}
