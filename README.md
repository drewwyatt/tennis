# Tennis (in Reason)

<p>Early research has found scoring in tennis to be... interesting. We&#39;re going to implement the scoreboard for a single game of tennis&nbsp;between two players, <code><var>A</var></code> and <code>B</code>. For each <strong>round</strong> I will tell you the winner <strong>of the round</strong>, and you&#39;ll give me the running scoreboard.&nbsp;Don&#39;t worry if you&#39;ve never played tennis before, we&#39;re going to break it down into the 3&nbsp;main rules for scoring an individual game, and then implement as many as we can!&nbsp;</p>

<hr />
<ul>
	<li>
	<p>Rule #1: After a player wins a round, their score increments. Whoever wins 4 rounds first, wins the game!</p>
	</li>
</ul>

<table border="1" cellpadding="1" cellspacing="1" style="text-align:center;width:500px;">
	<caption>&nbsp;</caption>
	<thead>
		<tr>
			<th scope="row">Round</th>
			<th scope="col">Winner (input)</th>
			<th scope="col"><span style="color:#e74c3c;">Score</span></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th scope="row">1</th>
			<td>A</td>
			<td><span style="color:#e74c3c;">1 - 0</span></td>
		</tr>
		<tr>
			<th scope="row">2</th>
			<td>A</td>
			<td><span style="color:#e74c3c;">2 - 0</span></td>
		</tr>
		<tr>
			<th scope="row">3</th>
			<td>A</td>
			<td><span style="color:#e74c3c;">3 - 0</span></td>
		</tr>
		<tr>
			<th scope="row">4</th>
			<td>B</td>
			<td><span style="color:#e74c3c;">3 - 1</span></td>
		</tr>
		<tr>
			<th scope="row">5</th>
			<td>A</td>
			<td><font color="#e74c3c">Game A</font></td>
		</tr>
	</tbody>
</table>

<hr />
<ul>
	<li>
	<p>Rule #2: Scores in tennis increment in unique ways. Like before the score&nbsp;starts at <code>0</code>,&nbsp;but then it&nbsp;increments to <code>15</code>, then <code>30</code>, then <code>40</code>, and (like before) winning 4 rounds still wins the game!</p>
	</li>
</ul>

<table border="1" cellpadding="1" cellspacing="1" style="text-align:center;width:500px;">
	<caption>&nbsp;</caption>
	<thead>
		<tr>
			<th scope="row">Round</th>
			<th scope="col">Winner (input)</th>
			<th scope="col"><span style="color:#e74c3c;">Score</span></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th scope="row">1</th>
			<td>A</td>
			<td><span style="color:#e74c3c;">15 - 0</span></td>
		</tr>
		<tr>
			<th scope="row">2</th>
			<td>A</td>
			<td><span style="color:#e74c3c;">30 - 0</span></td>
		</tr>
		<tr>
			<th scope="row">3</th>
			<td>A</td>
			<td><span style="color:#e74c3c;">40 - 0</span></td>
		</tr>
		<tr>
			<th scope="row">4</th>
			<td>B</td>
			<td><span style="color:#e74c3c;">40 - 15</span></td>
		</tr>
		<tr>
			<th scope="row">5</th>
			<td>A</td>
			<td><font color="#e74c3c">Game A</font></td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<div style="background:#eeeeee;border:1px solid #cccccc;padding:5px 10px;">You can now start&nbsp;running your code against the test suite and are <strong>strongly</strong> encouraged&nbsp;to do so.</div>

<div style="background:#eeeeee;border:1px solid #cccccc;padding:5px 10px;">The test suite will call your function with a single string representing the&nbsp;winner of each round&nbsp;and should return an array of strings representing the score after each round of the input. For the example above,&nbsp;the input string would be&nbsp;&nbsp;<code>&quot;AAABA&quot;</code>&nbsp;and output&nbsp;should should be&nbsp;<code>[&quot;15&nbsp;- 0&quot;, &quot;30 - 0&quot;, &quot;40 - 0&quot;, &quot;40 - 15&quot;, &quot;Game A&quot;]</code> (note the spaces surrounding the hyphen in the scores).</div>

<hr />
<ul>
	<li>Rule #3: Players must win by 2 rounds. Before when a player won a round after reaching&nbsp;<code>40</code>, they won the game. If the scores are tied <code>40</code> to <code>40</code>&nbsp;however, the player instead gets the Advantage, or&nbsp;<code>Adv</code>. If <strong>they</strong> win the next round <strong>with</strong> the&nbsp;<code>Adv</code>&nbsp;then they win the game! If the <strong>other</strong> player wins the next round, then the scores reset back to the tie game of <code>40</code> to <code>40</code>.</li>
</ul>

<table border="1" cellpadding="1" cellspacing="1" style="text-align:center;width:500px;">
	<caption>&nbsp;</caption>
	<thead>
		<tr>
			<th scope="row">Round</th>
			<th scope="col">Winner (input)</th>
			<th scope="col"><span style="color:#e74c3c;">Score</span></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th scope="row">1</th>
			<td>A</td>
			<td><span style="color:#e74c3c;">15 - 0</span></td>
		</tr>
		<tr>
			<th scope="row">2</th>
			<td>A</td>
			<td><span style="color:#e74c3c;">30 - 0</span></td>
		</tr>
		<tr>
			<th scope="row">3</th>
			<td>A</td>
			<td><span style="color:#e74c3c;">40 - 0</span></td>
		</tr>
		<tr>
			<th scope="row">4</th>
			<td>B</td>
			<td><span style="color:#e74c3c;">40 - 15</span></td>
		</tr>
		<tr>
			<th scope="row">5</th>
			<td>B</td>
			<td><font color="#e74c3c">40 - 30</font></td>
		</tr>
		<tr>
			<th scope="row">6</th>
			<td>B</td>
			<td><font color="#e74c3c">40 - 40</font></td>
		</tr>
		<tr>
			<th scope="row">7</th>
			<td>A</td>
			<td><font color="#e74c3c">Adv - 40</font></td>
		</tr>
		<tr>
			<th scope="row">8</th>
			<td>B</td>
			<td><font color="#e74c3c">40 - 40</font></td>
		</tr>
		<tr>
			<th scope="row">9</th>
			<td>B</td>
			<td><font color="#e74c3c">40 - Adv</font></td>
		</tr>
		<tr>
			<th scope="row">10</th>
			<td>B</td>
			<td><font color="#e74c3c">Game B</font></td>
		</tr>
	</tbody>
</table>
