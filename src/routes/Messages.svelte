<script>
  export let liveTemps;
  export let liveMoistures;
  export let face = "Happy";
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
      if (face === "Happy") {
        face = "Panting";
      } else {
        face = "HEEEEEEEEEEELLLLLLLLPPPPPPPPPPPPPPPLZ";
      }
    } else if (liveTemps[i] <= LOW_TEMP) {
      messages = [...messages, `Brrr! The ${SENSOR_LOCATION.get(i)} of your compost bin is too cold!`]
      if (face === "Happy") {
        face = "Freezing";
      } else {
        face = "HEEEEEEEEEEELLLLLLLLPPPPPPPPPPPPPPPLZ";
      }

    }
  }

  for (let i = 0; i <= 2; ++i) {
    if (liveMoistures[i] >= HIGH_MOISTURE) {
      messages = [...messages, `The ${SENSOR_LOCATION.get(i)} of your compost bin is sweating! It is too moist.`];
      if (face === "Happy") {
        face = "Sweating";
      } else {
        face = "HEEEEEEEEEEELLLLLLLLPPPPPPPPPPPPPPPLZ";
      }
    } else if (liveMoistures[i] <= LOW_MOISTURE) {
      messages = [...messages, `The ${SENSOR_LOCATION.get(i)} of your compost bin is parched! It is too dry.`]
      if (face === "Happy") {
        face = "ReachingForWater";
      } else {
        face = "HEEEEEEEEEEELLLLLLLLPPPPPPPPPPPPPPPLZ";
      }
    }
  }
</script>

<br />
{#each messages as message}
	<p>{message}</p><br />
{/each}
<br />&nbsp; <br />&nbsp;
<img src="/{face}.png" alt="gotchi" class="automaticResize" />
