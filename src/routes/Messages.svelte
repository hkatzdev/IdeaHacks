<script>
  export let liveTemps;
  export let liveMoistures;
  /**
	 * @type {string[]}
	 */
  let messages = [];
  const HIGH_TEMP = 100;
  const LOW_TEMP = 80;
  const HIGH_MOISTURE = 4;
  const LOW_MOISTURE = 2;
  const SENSOR_LOCATION = new Map([[0, "top"],[1, "middle"],[2, "bottom"]]);

  for (let i = 0; i <= 2; ++i) {
    if (liveTemps[i] >= HIGH_TEMP) {
      messages = [...messages, `Ouch! The ${SENSOR_LOCATION.get(i)} of your compost bin is too hot!`]
    } else if (liveTemps[i] <= LOW_TEMP) {
      messages = [...messages, `Brrr! The ${SENSOR_LOCATION.get(i)} of your compost bin is too cold!`]
    }
  }

  for (let i = 0; i <= 2; ++i) {
    if (liveMoistures[i] >= HIGH_MOISTURE) {
      messages = [...messages, `The ${SENSOR_LOCATION.get(i)} of your compost bin is sweating! It is too moist.`]
    } else if (liveMoistures[i] <= LOW_MOISTURE) {
      messages = [...messages, `The ${SENSOR_LOCATION.get(i)} of your compost bin is parched! It is too dry.`]
    }
  }
</script>

<br />
{#each messages as message}
	<p>{message}</p><br />
{/each}